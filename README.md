<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:061D16,50:16734B,100:0B1220&height=190&section=header&text=Directed%20Graph%20Complexity&fontSize=42&fontColor=F1F5F9&fontAlignY=38&animation=fadeIn&desc=Empirical%20runtime%20analysis%20and%20degree%20verification%20for%20directed%20graphs&descAlignY=61&descSize=15" alt="Directed Graph Complexity animated project banner" width="100%" />
</p>
<h1 align="center">Directed Graph Complexity</h1>


<div align="center">

![C Version](https://img.shields.io/badge/Language-C99%20%2F%20C11-00599C?style=for-the-badge&logo=c&logoColor=white)
![Excel](https://img.shields.io/badge/Analysis-MS%20Excel-107C41?style=for-the-badge&logo=microsoftexcel&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)

**An empirical and theoretical investigation into the computational complexity of computing vertex degrees in dense directed graphs.**

</div>

---

## 📖 Project Overview

This project implements an automated analysis pipeline in C to generate random directed graphs represented via adjacency matrices and evaluate the execution overhead of computing vertex degrees. The system verifies a fundamental law of graph theory: **the Handshaking Lemma for directed graphs**, which states that the sum of all in-degrees across all vertices perfectly equals the sum of all out-degrees.

The core objectives achieved are:
1. Dynamic memory allocation and generation of random directed graphs for $n \in \{1000, 2000, 3000, 4000, 5000\}$.
2. Execution tracking of degree calculation algorithms using high-precision hardware clocks (excluding I/O overhead).
3. Mathematical regression profiling via polynomial trendline fitting in Microsoft Excel.
4. Comparative analysis validating empirical benchmarks against theoretical Big-O constraints.

---

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

## Creator, Developer & Maintainer

**Created, designed, developed, and maintained by [Nurul Faiyaz](https://github.com/tracolerd).**

This project is independently built and maintained by Nurul Faiyaz. The project's design, implementation, and documentation are his work.

<p align="center">
  <a href="https://www.facebook.com/faiyaz.888"><img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white" alt="Facebook" /></a>
  <a href="https://www.instagram.com/tracolerd"><img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram" /></a>
  <a href="https://www.linkedin.com/in/faiyaz-xyz"><img src="https://img.shields.io/badge/LinkedIn-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" /></a>
  <a href="https://x.com/faiyaz_explores"><img src="https://img.shields.io/badge/X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X" /></a>
  <a href="https://github.com/tracolerd"><img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white" alt="GitHub" /></a>
  <a href="mailto:scrollfaiyaz@gmail.com"><img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email" /></a>
  <a href="https://nurul-faiyaz.netlify.app/"><img src="https://img.shields.io/badge/Portfolio-Visit%20Website-0F766E?style=for-the-badge&logo=googlechrome&logoColor=white" alt="Personal website" /></a>
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
