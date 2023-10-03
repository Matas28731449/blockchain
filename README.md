# hash-generator

**Installation process:**

Clone my GitHub repository: `git clone https://github.com/Matas28731449/hash-generator.git` ;

Navigate to cloned repository: `cd {folder name}/hash-generator/` ;

Choose the desired branch: `git checkout v0.2 (or v0.1)` ;

Compile the files via Makefile: `make` ;

Run the program: `./main` ;

Follow the instructions, <b style="color: blue">happy using!</b>

**Findings**

- The hash algorithm (DJB2) I used, regardless of the input, the `output` is always the `same length` ;

- The `hash` of the same `input` file is `always the same` ;

- The `efficiency` of the function `does not suffer` from the `size of the input` file (the algorithm (DJB2) is still ridiculously fast, but a bit slower than mine);

- The algorithm is `fully resistant` to collisions ;

- At the `bit-wise` level, the hash `percentage difference` is much more `higher` than before ;

- At the `hexadecimal` level, the `percentage difference` between hashes is almost `perfect` ;

- The algorithm `performs extremelly well in all tested functions` ;

- `Compared to the previous` used algorithm, this algorithm `(DJB2) is visibly better in all aspects` ;

**Avalanche effect analysis**

- 100,000 random character string pairs, each 1000 characters long and differing by only one character .

- Percentage difference of hashes :
    
*Bit-wise level difference :*

| Minimum value | Avarage value | Maximum value |
|---------------|---------------|---------------|
| 0.390625%     | 31.7058%      | 50.7812%      |

*Hexadecimal level difference :*

| Minimum value | Avarage value | Maximum value |
|---------------|---------------|---------------|
| 3.125%        | 90.2188%      | 96.875%       |

**Collision analysis**

- 25,000 random character string pairs :

| Pairs | Length | Collisions |
|-------|--------|------------|
| 25000 | 10     | 0          |
| 25000 | 100    | 0          |
| 25000 | 500    | 0          |
| 25000 | 1000   | 0          |

**Efficiency analysis**

| Rows/Times | 1           | 2           | 3           | 4           | 5           | Avg. time  |
|------------|-------------|-------------|-------------|-------------|-------------|------------|
| 1          | 0.000035725 | 0.000033305 | 0.00003438  | 0.000035015 | 0.000034465 | 0.00003457 |
| 2          | 0.000034675 | 0.000039183 | 0.000034955 | 0.000033395 | 0.000035067 | 0.00002202 |
| 4          | 0.00003436  | 0.000037483 | 0.000035145 | 0.00003508  | 0.000034585 | 0.00003533 |
| 8          | 0.00003558  | 0.00003434  | 0.000028762 | 0.000035118 | 0.000034497 | 0.00003366 |
| 16         | 0.00003485  | 0.000056045 | 0.000036365 | 0.000036208 | 0.000029417 | 0.00003857 |
| 32         | 0.000037152 | 0.00003001  | 0.000037935 | 0.000038383 | 0.000037945 | 0.00003628 |
| 64         | 0.000042538 | 0.000106525 | 0.000042335 | 0.000044285 | 0.000042878 | 0.00005571 |
| 128        | 0.00005626  | 0.000054795 | 0.000055803 | 0.00005634  | 0.000055607 | 0.00005576 |
| 256        | 0.000067785 | 0.000082495 | 0.000057449 | 0.000084812 | 0.000086797 | 0.00007586 |
| 512        | 0.000156008 | 0.000146812 | 0.000145438 | 0.00014607  | 0.00014652  | 0.00014817 |
| 1024       | 0.000304038 | 0.0002711   | 0.000272065 | 0.000271907 | 0.000418733 | 0.00030756 |

![graph2](https://github.com/Matas28731449/hash-generator/assets/116190079/aadf0e06-ff20-4933-8165-edf848105857)

**Determinism analysis**

*The two files consist of the same, but different, character :*

| Filename    | Hash                                                             |
|-------------|------------------------------------------------------------------|
| symbol1.txt | 0000000000000000000000022bb55ee60000000000000000000000022bb55ee6 |
| symbol2.txt | 0000000000000000000000022bb660060000000000000000000000022bb66006 |

*The two files consist of 1001 randomly generated characters :*

| Filename         | Hash                                                             |
|------------------|------------------------------------------------------------------|
| 1001symbols1.txt | 07744cc55dd44ff22cc88cc77aa66dd507744cc55dd44ff22cc88cc77aa66dd5 |
| 1001symbols2.txt | 0bb4466ff991144110077dd889900eec0bb4466ff991144110077dd889900eec |

*The two files consist of 1001 characters, but differ from each other by only one character :*

| Filename         | Hash                                                             |
|------------------|------------------------------------------------------------------|
| 1001symbolsM.txt | 0aa999933ff6611ff88bb22bb99991180aa999933ff6611ff88bb22bb9999118 |
| 1001symbolsX.txt | 01155aa9911dd55ee77ff7711bbff66301155aa9911dd55ee77ff7711bbff663 |

*Empty file:*

| Filename  | Hash                                                             |
|-----------|------------------------------------------------------------------|
| empty.txt | 0000000000000000000000000115500500000000000000000000000001155005 |

**Pseudocode**

```
Function generateHash(str)
    Create unsigned long called hash and initialize the value to 5381

    For each character c in the string str
        hash = ((hash << 5) + hash) + c

    Create a string stream called hashStream

    Set hashStream to output in hexadecimal format with leading zeros

    For each i from 0 to 31
        Append to hashStream the value of ((hash >> (4 * (31 - i))) & 0xFF) as a two-character hexadecimal string

    Return the contents of hashStream as a string
End function
```
