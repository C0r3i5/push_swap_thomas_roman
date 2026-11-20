*This project has been created as part of the 42 curriculum by twalter, rulrich.*

# Description



## Algorithm Explanation & Justification

### List

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
```mermaid
flowchart TB
	%% Pointer
	HEAD([HEAD]) -->|point to| Node1

	%% Knoten 3
	subgraph Node3 [Knoten 3]
		direction TB
		N3_P["top: Node 2"] ~~~ N3_I["position: 2"] ~~~ N3_V["value: 30"] ~~~ N3_N["bottom: Node 1"]
	end

	%% Knoten 2
	subgraph Node2 [Knoten 2]
		direction TB
		N2_P["top: Node 1"] ~~~ N2_I["position: 1"] ~~~ N2_V["value: 20"] ~~~ N2_N["bottom: Node 3"]
	end

	%% Knoten 1
	subgraph Node1 [Knoten 1]
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


# Instuctions

To compile the library use the provided makefile and the command

	make 

This command compile the whole library and create the libftprintf.a file.
Same as 

	make all

and

	make push_swap

To clean the folder and delete the created .o files use

	make clean

To clean also the created libftprintf.a use

	make fclean

To clean and recreate with one command use

	make re

# Resources

## AI use
With the help of AI, I discussed basic C topics and topics that my fellow peers couldn't answer or that were unclear to all of us.

Some unit tests include suggestions from the AI "Google Gemini".

Some translations from german into english are supported by AI translation.

## Used Resources:
- Peers :)
- Stackoverflow
- Gemini

## Files in the project folder
