# UBI 503 – Data Structures and Algorithms (590616 – 2526G)  
## 7th Homework

**Assignment Date:** 02.12.2025  
**Due Date:** 09.12.2025  

**Course:** Data Structures and Algorithms  
**Institution:** Ege University – Graduate School of Natural and Applied Sciences  
**Department:** International Computer Institute  
**Instructors:** Prof. Dr. Geylani KARDAŞ, Res. Asst. Cemil Aybars URAL  
**Student:** Bahtınur Şener  
**Student Number:** 91250000022  

---

## 📘 Homework Description

This repository contains the solution to **Exercise 12.8** from:

> Paul Deitel, Harvey Deitel,  
> _C How to Program (7th Edition)_, Prentice Hall, 2013.

### Problem 12.8 – Merging after Inserting into Ordered Lists (Slightly Modified)

Two separate linked lists are created as follows:

- The first linked list contains **5 random integers between 0 and 50**, inserted in ascending order.
- The second linked list contains **5 random integers between 0 and 100**, inserted in ascending order.

After constructing these lists, they are merged into **a single ordered linked list** by defining a function:

```c
struct Node* merge(struct Node* list1, struct Node* list2);
