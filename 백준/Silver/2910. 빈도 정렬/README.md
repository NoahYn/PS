# [Silver III] 빈도 정렬 - 2910 

[문제 링크](https://www.acmicpc.net/problem/2910) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 정렬

### 문제 설명

<p>Mirko is a great code breaker. He knows any cipher in the world can be broken by frequency analysis.</p>

<p>He has completely the wrong idea what frequency analysis is, however.</p>

<p>He intercepted an enemy message. The message consists of N numbers, smaller than or equal to C Mirko belives freqency analysis consists of sorting this sequence so that more frequent numbers appear before less frequent ones.</p>

<p>Formally, the sequence must be sorted so that given any two numbers X and Y , X appears before Y if the number of times X appears in the original sequence is larger than the number of time Y does. If the number of appearances is equal, the number whoes value appears sooner in the input should appear sooner in the sorted sequence.</p>

<p>Help Mirko by creating a "frequency sorter".</p>

### 입력 

 <p>First line of input contains two integers, N (1 ≤ N ≤ 1 000), length of message, and C (1 ≤ C ≤ 1 000 000 000), the number from task description.</p>

<p>Next line contains N integers smaller than or equal to C, message itself.</p>

### 출력 

 <p>First and only line of output should contain N numbers, the sorted sequence.</p>

<p> </p>

