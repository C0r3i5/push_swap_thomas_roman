*This project has been created as part of the 42 curriculum by twalter, rulrich.*

# Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of unique integers in ascending order on **stack A**, using an auxiliary **stack B** and a restricted set of stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), while minimizing the total number of moves.

This implementation supports four sorting strategies:
- **Simple** ($O(n^2)$)
- **Medium** ($O(n\sqrt{n})$)
- **Complex** ($O(n \log n)$)
- **Adaptive** *(default)*: automatically chooses between Simple, Medium, and Complex based on the initial disorder of stack A.

An optional `--bench` flag outputs the computed disorder, selected strategy, complexity class, total operations, and per-operation counts to `stderr`.

```mermaid
flowchart TD
	Start(["Start: main(argc, argv)"]) --> CheckArgc{"argc < 2?"}
	CheckArgc -->|Yes| Exit0(["Exit (0)"])
	CheckArgc -->|No| Parse["parse_arguments(argc, argv, &mode, &lst_a)"]

	Parse -->|"Error (-1)"| PrintErr["Write 'Error\\n' to stderr"]
	PrintErr --> FreeErr["free_stack(&head_a)"]
	FreeErr --> Exit1(["Exit (1)"])

	Parse -->|"OK (0)"| CheckSize{"size_a == 0?"}
	CheckSize -->|Yes| Exit0
	CheckSize -->|No| Disorder["compute_disorder(mode)"]

	Disorder --> Resolve{"resolve_algo(&mode)"}
	Resolve -->|"--simple or (adaptive & d < 0.2)"| Simple["used_algo = SIMPLE"]
	Resolve -->|"--medium or (adaptive & 0.2 <= d < 0.5)"| Medium["used_algo = MEDIUM"]
	Resolve -->|"--complex or (adaptive & d >= 0.5)"| Complex["used_algo = COMPLEX"]

	Simple --> IsSorted{"disorder == 0.0 or size_a < 2?"}
	Medium --> IsSorted
	Complex --> IsSorted

	IsSorted -->|Yes| BenchCheck{"bench_active == 1?"}
	IsSorted -->|No| RunSort["Run selected sort & print ops to stdout"]
	RunSort --> BenchCheck

	BenchCheck -->|Yes| PrintBench["print_bench(mode) to stderr"]
	BenchCheck -->|No| FreeAll["free_stack(A) & free_stack(B)"]
	PrintBench --> FreeAll
	FreeAll --> Exit0
```

<details>
	<summary>Details: Argument & Input Parsing (parse_arguments)</summary>

```mermaid
flowchart TD
	Start(["parse_arguments(argc, argv, mode, lst_a)"]) --> Init["idx = 1"]
	Init --> LoopArg{"idx < argc?"}
	LoopArg -->|No| RetOK(["Return 0"])
	LoopArg -->|Yes| IsFlag{"is_flag(argv[idx], mode)"}

	IsFlag -->|"1 (valid flag)"| NextArg["idx++"]
	IsFlag -->|"-1 (duplicate strategy flag)"| RetErr(["Return -1"])
	IsFlag -->|"0 (number arg)"| Split["parts = ft_split(argv[idx], ' ')"]

	Split --> EmptyCheck{"parts == NULL or parts[0] == NULL?"}
	EmptyCheck -->|Yes| FreeSplitErr["free_split(parts)"] --> RetErr
	EmptyCheck -->|No| PartLoop{"parts[j] != NULL?"}

	PartLoop -->|No| FreeSplitOK["free_split(parts)"] --> NextArg
	PartLoop -->|Yes| Atoi["node = atoi_strict_node(parts[j])"]

	Atoi --> NodeNull{"node == NULL? (non-int / overflow)"}
	NodeNull -->|Yes| FreeBoth["free_split(parts) & free(node)"] --> RetErr
	NodeNull -->|No| Append{"append_unique(lst_a, node, mode)"}

	Append -->|"-1 (duplicate value)"| FreeBoth
	Append -->|"0 (added)"| NextPart["j++"] --> PartLoop

	NextArg --> LoopArg
```

</details>

<details>
    <summary>Details: Simple, Medium & Complex Sorting Strategies</summary>

```mermaid
flowchart LR
	Start(["start_sort(mode)"]) --> Dispatch{"mode.used_algo"}
	Dispatch -->|SIMPLE| S["sort_simple(mode) - O(n^2)"]
	Dispatch -->|MEDIUM| M["sort_medium(mode) - O(n*sqrt(n))"]
	Dispatch -->|COMPLEX| C["sort_complex(mode) - O(n log n)"]
```

</details>

## Algorithm Explanation & Justification

### List

Both stacks (`A` and `B`) are implemented as **circular doubly-linked lists** (`t_node`). Each node stores:
- `value`: the integer value
- `position`: the 0-based index from the top of the stack (`0` = head)
- `top`: pointer to the previous node (the head's `top` points to the last node)
- `bottom`: pointer to the next node (the last node's `bottom` points to the head)

**Why a circular doubly-linked list?**
- **O(1) rotations:** `ra`/`rb` (`head = head->bottom`) and `rra`/`rrb` (`head = head->top`) only move the head pointer without traversing the list to find the tail.
- **O(1) push and swap:** `pa`/`pb` and `sa`/`sb` only relink a fixed number of pointers at the head, avoiding array shifts.

<details>
    <summary>Details: Circular double-linked list (Diagram 1)</summary>

```mermaid
classDiagram
	direction LR

	class head {
		Pointer to Node 1
	}

	class Node1 {
		+top : *Node3
		+position : 0
		+value : 1
		+bottom : *Node2
	}

	class Node2 {
		+top : *Node1
		+position : 1
		+value : 2
		+bottom : *Node3
	}

	class Node3 {
		+top : *Node2
		+position : 2
		+value : 3
		+bottom : *Node1
	}

	head --> Node1 : point to

	Node1 --> Node2 : bottom
	Node2 --> Node1 : top

	Node2 --> Node3 : bottom
	Node3 --> Node2 : top

	Node1 --> Node3 : top
	Node3 --> Node1 : bottom

```

</details>

<details>
    <summary>Details: Circular double-linked list (Diagram 2)</summary>

```mermaid
flowchart TB
	%% Pointer
	HEAD([HEAD]) -->|point to| Node1

	%% Node 3
	subgraph Node3 [Node 3]
		direction TB
		N3_P["top: Node 2"] ~~~ N3_I["position: 2"] ~~~ N3_V["value: 30"] ~~~ N3_N["bottom: Node 1"]
	end

	%% Node 2
	subgraph Node2 [Node 2]
		direction TB
		N2_P["top: Node 1"] ~~~ N2_I["position: 1"] ~~~ N2_V["value: 20"] ~~~ N2_N["bottom: Node 3"]
	end

	%% Node 1
	subgraph Node1 [Node 1]
		direction TB
		N1_P["top: Node 3"] ~~~ N1_I["position: 0"] ~~~ N1_V["value: 10"] ~~~	N1_N["bottom: Node 2"]
	end

	Node1 -->|bottom| Node2
	Node2 -->|bottom| Node3
	Node3 -->|bottom| Node1

	Node1 -->|top| Node3
	Node2 -->|top| Node1
	Node3 -->|top| Node2
```

</details>

### Adaptive Strategy

When `--adaptive` (or no strategy flag) is used, the program computes the initial `disorder` ratio ($0.0$ = already sorted, $1.0$ = completely reversed) and selects the sorting strategy accordingly:
- `disorder < 0.2` → **Simple** ($O(n^2)$)
- `0.2 <= disorder < 0.5` → **Medium** ($O(n\sqrt{n})$)
- `disorder >= 0.5` → **Complex** ($O(n \log n)$)

# Instructions

## Build

To compile the program use the provided makefile and the command

	make 

This command compiles the program and creates the push_swap binary.
Same as 

	make all

and

	make push_swap

To clean the folder and delete the created .o files use

	make clean

To clean also the created binary and .a files use

	make fclean

To clean and recreate with one command use

	make re

## Usage

Run `push_swap` with a list of integers (as separate arguments or a single quoted string):

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

### Strategy & Benchmark Flags

- --adaptive (default): Selects the strategy automatically based on the initial disorder.
- --simple: Forces the O(n²) algorithm.
- --medium: Forces the O(n√n) algorithm.
- --complex: Forces the O(n log n) algorithm.
- --bench: Prints disorder, selected strategy, total operation count, and individual operation counts to stderr.

```bash
./push_swap --medium 4 67 3 87 23
./push_swap --bench 4 67 3 87 23
./push_swap --bench --complex "4 67 3 87 23"
```

# Resources

## AI use
All code and architectural decisions were written by us. AI (Google Gemini) was used strictly in an advisory, read-only role, never to generate the complete solution, and every suggestion was critically reviewed, tested, and discussed between us so that we fully understand and take responsibility for every line of code.

Specifically, AI assisted with:
- Explaining C concepts and answering questions that remained unclear after discussing them with peers
- Suggesting ideas for unit tests and edge-case testing
- Translating and proofreading documentation (Doxygen comments and README) from German into English
- Assisting with the Mermaid diagrams in README.md

## Used Resources:
- Peers :)
- Stackoverflow
- Gemini

## Files in the project folder
- `push_swap.c`: Program entry point, error handling, and cleanup.
- `push_swap.h`: Data structures (`t_node`, `t_mode`, `t_algo`) and prototypes.
- `arguments.c`: CLI flag and integer argument parsing.
- `node_functions.c`: Node creation, duplicate check, disorder calculation, and list healing.
- `stack_operations_1.c` – `stack_operations_4.c`: Stack operations (`sa`, `sb`, `ss`, `ra`, `rb`, `rr`,
`rra`, `rrb`, `rrr`, `pa`, `pb`).
- `sort_selector.c`: Adaptive strategy resolution and sort dispatching.
- `bench.c`: Benchmark output formatting to `stderr`.
- `Makefile`: Build rules for `push_swap` and `ft_printf`.
- `ft_printf/`: Custom `ft_printf` and `libft` libraries.
