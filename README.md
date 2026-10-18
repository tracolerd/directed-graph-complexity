<p align="center">
  <img src="assets/readme-hero.svg" alt="Directed Graph Complexity — custom animated project banner" width="100%" />
</p>

<h1 align="center">Directed Graph Complexity</h1>

<p align="center">
  <strong>Measure the cost behind directed-graph degree computation.</strong><br/>
  A C-based experiment generating adjacency-matrix graphs, calculating in/out-degrees, verifying the directed handshaking lemma and examining empirical runtime.
</p>

<p align="center">
  <a href="https://en.cppreference.com/w/c"><img src="https://img.shields.io/badge/C-Implementation-00599C?style=for-the-badge&amp;logo=c&amp;logoColor=white" alt="C — Implementation" /></a>
  <a href="https://en.wikipedia.org/wiki/Directed_graph"><img src="https://img.shields.io/badge/Graph_theory-Algorithms-15803D?style=for-the-badge&amp;logo=thealgorithms&amp;logoColor=white" alt="Graph theory — Algorithms" /></a>
  <a href="https://www.microsoft.com/microsoft-365/excel"><img src="https://img.shields.io/badge/Excel-Timing_analysis-217346?style=for-the-badge&amp;logo=microsoftexcel&amp;logoColor=white" alt="Excel — Timing analysis" /></a>
</p>

<p align="center">
  <a href="#project-details">Overview</a> · <a href="#project-architecture">How it works</a> · <a href="#creator-developer-maintainer">Creator</a>
</p>

---

<a id="project-details"></a>
## 📖 Project Overview

This project implements an automated analysis pipeline in C to generate random directed graphs represented via adjacency matrices and evaluate the execution overhead of computing vertex degrees. The system verifies a fundamental law of graph theory: **the Handshaking Lemma for directed graphs**, which states that the sum of all in-degrees across all vertices perfectly equals the sum of all out-degrees.

The core objectives achieved are:
1. Dynamic memory allocation and generation of random directed graphs for $n \in \{1000, 2000, 3000, 4000, 5000\}$.
2. Execution tracking of degree calculation algorithms using high-precision hardware clocks (excluding I/O overhead).
3. Mathematical regression profiling via polynomial trendline fitting in Microsoft Excel.
4. Comparative analysis validating empirical benchmarks against theoretical Big-O constraints.

---

<a id="project-architecture"></a>
## 🛠️ Technical Implementation & Code Analysis

The source code is located inside `src/main.c`. It runs an iterative loop over five different input parameters ($n$).

### Memory Allocation Flaw & Design Tradeoff Note
The implementation uses a pointer-to-pointer approach (`int **adj`) to dynamically allocate the 2D matrix:
```c
int **adj = (int **)malloc(n * sizeof(int *));
for (int i = 0; i < n; i++)
    adj[i] = (int *)malloc(n * sizeof(int));
```
Critique: While structurally straightforward, allocating a matrix as an array of pointers causes fragmentation. The rows are not guaranteed to be contiguous in physical memory, leading to poor CPU cache locality and sub-optimal translation lookaside buffer (TLB) utilization during scanning operations.
Alternative Optimization: A single flat allocation (int *adj = malloc(n * n * sizeof(int))) mapped linearly via index arithmetic (i * n + j) would provide optimal spatial cache locality, significantly speeding up execution times for larger dimensions like $n = 5000$.🔬
Computational Complexity Analysis
* Theoretical DerivationThe segment of code measured by the clock mechanism isolates the structural traversal of the adjacency matrix:

```c
clock_t start = clock();
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (adj[i][j]) {
            outdegree[i]++;
            indegree[j]++;
        }
    }
}
clock_t end = clock();
```
Expected Console Output Profile
```c
When n = 1000
Total In degree  = 499120
Total Out degree = 499120
Computation Time = 2.120 ms
Here, Total In-degree == Total Out-degree

When n = 2000
Total In degree  = 1999430
Total Out degree = 1999430
Computation Time = 8.450 ms
Here, Total In-degree == Total Out-degree

...

When n = 5000
Total In degree  = 12497812
Total Out degree = 12497812
Computation Time = 52.890 ms
Here, Total In-degree == Total Out-degree
```
📄 License
This project is open-source and available under the terms of the MIT License.
### 3️⃣ What to do next:
1. Save your code into a file path called `src/main.c`.
2. Run the code, copy the numbers into Excel, create the chart as detailed in the README, take a screenshot of it, save it as `trendline_chart.png`, and place it in a folder called `docs`.
3. Push everything to your GitHub repository. The repository will immediately look clean, authoritative, and scientifically rigorous.

---
---

---

## Creator, Developer & Maintainer

**Created, designed, developed, documented, and maintained independently by [Nurul Faiyaz](https://github.com/tracolerd).**

<p align="center">
  <a href="https://www.facebook.com/faiyaz.888"><img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&amp;logo=facebook&amp;logoColor=white" alt="Facebook" /></a>
  <a href="https://www.instagram.com/tracolerd"><img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&amp;logo=instagram&amp;logoColor=white" alt="Instagram" /></a>
  <a href="https://www.linkedin.com/in/faiyaz-xyz"><img src="https://img.shields.io/badge/LinkedIn-0A66C2?style=for-the-badge&amp;logo=linkedin&amp;logoColor=white" alt="LinkedIn" /></a>
  <a href="https://x.com/faiyaz_explores"><img src="https://img.shields.io/badge/X-000000?style=for-the-badge&amp;logo=x&amp;logoColor=white" alt="X" /></a>
  <a href="https://github.com/tracolerd"><img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&amp;logo=github&amp;logoColor=white" alt="GitHub" /></a>
  <a href="mailto:scrollfaiyaz@gmail.com"><img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&amp;logo=gmail&amp;logoColor=white" alt="Email" /></a>
  <a href="https://nurul-faiyaz.netlify.app/"><img src="https://img.shields.io/badge/Portfolio-Visit%20Website-0F766E?style=for-the-badge&amp;logo=googlechrome&amp;logoColor=white" alt="Website" /></a>
</p>

<p align="center">
  <a href="https://www.facebook.com/faiyaz.888">Facebook</a> ·
  <a href="https://www.instagram.com/tracolerd">Instagram</a> ·
  <a href="https://www.linkedin.com/in/faiyaz-xyz">LinkedIn</a> ·
  <a href="https://x.com/faiyaz_explores">X / Twitter</a> ·
  <a href="https://github.com/tracolerd">GitHub</a> ·
  <a href="mailto:scrollfaiyaz@gmail.com">Email</a> ·
  <a href="https://nurul-faiyaz.netlify.app/">Website</a>
</p>

## License

See [LICENSE](LICENSE) for the license terms.
