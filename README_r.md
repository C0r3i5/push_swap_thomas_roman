# Ablaufdiagramme (Flowcharts) für einfache $O(n^2)$-Algorithmen

Dieses Dokument enthält die visuellen Ablaufdiagramme (als **Mermaid-Flowcharts**) sowie die logische Schrittfolge für die vier geforderten Basis-Strategien aus der Komplexitätsklasse $O(n^2)$:

1. **Insertion Sort Adaptation** (Einfügesortieren)
2. **Selection Sort Adaptation** (Auswahlsortieren)
3. **Bubble Sort Adaptation** (Blasensortieren)
4. **Simple Min/Max Extraction Methods** (Einfache Min/Max-Extraktionsmethoden)

---

## 1. Insertion Sort Adaptation (Einfügesortieren)

**Grundidee:** Das Array $A$ der Länge $n$ wird in einen bereits sortierten linken Teil und einen unsortierten rechten Teil unterteilt. In jedem Schritt wird das erste Element des unsortierten Teils (`key`) an die richtige Position im sortierten Teil verschoben.

```mermaid
flowchart TD
    Start(["Start: Array A der Länge n"]) --> InitI["i = 1"]
    InitI --> CondI{"i < n ?"}
    CondI -->|Nein| End(["Ende: A ist sortiert"])
    CondI -->|Ja| SetKey["key = A[i]<br/>j = i - 1"]
    SetKey --> CondJ{"j >= 0 UND A[j] > key ?"}
    CondJ -->|Ja| Shift["A[j + 1] = A[j]<br/>j = j - 1"]
    Shift --> CondJ
    CondJ -->|Nein| Insert["A[j + 1] = key<br/>i = i + 1"]
    Insert --> CondI
```

* **Best Case:** $O(n)$ (bereits sortiert)
* **Worst / Average Case:** $O(n^2)$

---

## 2. Selection Sort Adaptation (Auswahlsortieren)

**Grundidee:** Das Array $A$ wird schrittweise von links nach rechts aufgebaut. In jedem Durchlauf $i$ wird im verbleibenden unsortierten Teilbereich $[i, n-1]$ das kleinste Element gesucht (`min_idx`) und mit dem Element an Position $i$ getauscht.

```mermaid
flowchart TD
    Start(["Start: Array A der Länge n"]) --> InitI["i = 0"]
    InitI --> CondI{"i < n - 1 ?"}
    CondI -->|Nein| End(["Ende: A ist sortiert"])
    CondI -->|Ja| SetMin["min_idx = i<br/>j = i + 1"]
    SetMin --> CondJ{"j < n ?"}
    CondJ -->|Ja| CheckMin{"A[j] < A[min_idx] ?"}
    CheckMin -->|Ja| UpdateMin["min_idx = j"]
    CheckMin -->|Nein| IncJ["j = j + 1"]
    UpdateMin --> IncJ
    IncJ --> CondJ
    CondJ -->|Nein| Swap["Tausche A[i] und A[min_idx]<br/>i = i + 1"]
    Swap --> CondI
```

* **Best / Average / Worst Case:** Immer $O(n^2)$ Vergleiche, maximal $O(n)$ Vertauschungen.

---

## 3. Bubble Sort Adaptation (Blasensortieren)

**Grundidee:** Benachbarte Elemente $A[j]$ und $A[j+1]$ werden paarweise verglichen und bei falscher Reihenfolge vertauscht. Dadurch wandert das jeweils größte Element wie eine Blase an das Ende des unsortierten Bereichs.

```mermaid
flowchart TD
    Start(["Start: Array A der Länge n"]) --> InitI["i = 0"]
    InitI --> CondI{"i < n - 1 ?"}
    CondI -->|Nein| End(["Ende: A ist sortiert"])
    CondI -->|Ja| InitJ["j = 0"]
    InitJ --> CondJ{"j < n - i - 1 ?"}
    CondJ -->|Ja| Compare{"A[j] > A[j + 1] ?"}
    Compare -->|Ja| Swap["Tausche A[j] und A[j + 1]"]
    Compare -->|Nein| IncJ["j = j + 1"]
    Swap --> IncJ
    IncJ --> CondJ
    CondJ -->|Nein| IncI["i = i + 1"]
    IncI --> CondI
```

* **Worst / Average Case:** $O(n^2)$
* **Hinweis zur Optimierung:** Durch ein `swapped`-Flag kann der Algorithmus vorzeitig abbrechen, falls in einem Durchlauf kein Tausch stattgefunden hat (Best Case $O(n)$).

---

## 4. Simple Min/Max Extraction Methods (Min/Max-Extraktion)

**Grundidee:** Aus einer unsortierten Eingabemenge $U$ wird in jedem Schritt durch einen linearen Suchlauf ($O(n)$) das globale Minimum (oder Maximum, bzw. beides gleichzeitig bei beidseitiger Extraktion) ermittelt, aus $U$ entfernt und an die Ergebnisstruktur $S$ angefügt. Da dies $n$-mal wiederholt wird, ergibt sich eine Gesamtlaufzeit von $O(n^2)$.

```mermaid
flowchart TD
    Start(["Start: Unsortierte Liste U, Ergebnisliste S = []"]) --> CheckEmpty{"Ist U leer?"}
    CheckEmpty -->|Ja| End(["Ende: S enthält alle sortierten Elemente"])
    CheckEmpty -->|Nein| InitScan["Setze min_val = U[0]"]
    InitScan --> ScanLoop["Durchlaufe alle Elemente x in U:<br/>Falls x < min_val, setze min_val = x"]
    ScanLoop --> Extract["Entferne min_val aus U<br/>und hänge es an S an"]
    Extract --> CheckEmpty
```

* **Variante (Gleichzeitige Min- & Max-Extraktion):** Pro Durchlauf werden sowohl das Minimum als auch das Maximum gesucht und an den linken bzw. rechten Rand der Zielstruktur gesetzt. Die Anzahl der Durchläufe halbiert sich auf $\lceil n/2 \rceil$, die asymptotische Laufzeit bleibt jedoch $O(n^2)$.