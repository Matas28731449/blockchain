# hash-generator

**Pseudocode**

```
Function generateHash(str)
    Create an array of 8 integers called hash and initialize all elements to 0

    For each character c in the string str
        For each i from 0 to 7
            Increment hash[i] by the result of c * (i + 1)

    Create a string stream called hashStream

    Set hashStream to output in hexadecimal format with leading zeros

    For each i from 0 to 7
        Add hash[i] to hashStream with a width of 8 characters

    Return the contents of hashStream as a string
End Function
```