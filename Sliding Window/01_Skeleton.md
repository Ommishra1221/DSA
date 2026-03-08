## **Blueprint – Aditya Verma Sliding Window Template**

### **When to use Sliding Window**

- You have an array/string
- You need a subarray/substring of size `K` **or**
    
    need the **longest/shortest substring** satisfying some condition
    

---

### **Two types**

1. **Fixed-size window**
    - Window size is constant (`K`)
    - Example: Max sum subarray of size `K`, First negative number of size `K`
    
    **Steps**:
    
    1. Take two pointers `i` (start), `j` (end), and a variable to store the result.
    2. Expand `j` until window size = `K`
    3. Once window size is reached, process the result, then shrink from `i`.
    
    **Skeleton**:
    
    ```
    
    while (j < N) {
        // calculation for j
        if (window size < K) {
            j++;
        } else if (window size == K) {
            // ans update
            // remove calculation for i
            i++; j++;
        }
    }
    
    ```




1. **Variable-size window**
    - Window size is not fixed, we adjust until a condition is met
    - Example: Longest substring with at most `K` distinct chars
    
    **Steps**:
    
    1. Expand `j` and keep updating your frequency map or counts.
    2. If condition is violated, shrink from `i` until condition is valid again.
    3. Update answer when condition is satisfied.
    
    **Skeleton**:
    
    ```

    while (j < N) {
        // include element at j
        if (condition satisfied) {
            // update answer
            j++;
        } else {
            while (condition violated) {
                // remove element at i
                i++;
            }
            j++;
        }
    }
    
    ```
