# hash-generator

**Installation process:**

Clone my GitHub repository: `git clone https://github.com/Matas28731449/hash-generator.git` ;

Navigate to cloned repository: `cd {folder name}/hash-generator/` ;

Compile the files via Makefile: `make` ;

Run the program: `./main` ;

Follow the instructions, <b style="color: blue">happy using!</b>

**Findings**

- The hash algorithm I created, regardless of the input, the `output` is always the `same length` ;

- The `hash` of the same `input` file is `always the same` ;

- The `efficiency` of the function `does not suffer` from the `size of the input` file (the algorithm is ridiculously fast);

- The algorithm is `partially resistant` to collisions (the longer the string, the lower the probability of collision) ;

- At the `bit-wise` level, the hash `percentage difference` is `low`, this is because there are more bits as units ;

- At the `hexadecimal` level, the `percentage difference` between hashes is `avarage` ;

- The algorithm `performs well in basic functions`, which is why it can be described as demonstrative ;

- If safety is considered, `collision resistence` and `avalanche effect could perform better` .

**Avalanche effect analysis**

- 100,000 random character string pairs, each 1000 characters long and differing by only one character .

- Percentage difference of hashes :
    
*Bit-wise level difference :*

| Minimum value | Avarage value | Maximum value |
|---------------|---------------|---------------|
| 2.34375%      | 8.99111%      | 22.0703%      |

*Hexadecimal level difference :*

| Minimum value | Avarage value | Maximum value |
|---------------|---------------|---------------|
| 12.5%         | 27.6937%      | 50%           |

**Collision analysis**

- 25,000 random character string pairs :

| Pairs | Length | Collisions |
|-------|--------|------------|
| 25000 | 10     | 113        |
| 25000 | 100    | 26         |
| 25000 | 500    | 18         |
| 25000 | 1000   | 6          |

**Efficiency analysis**

| Rows/Times | 1           | 2           | 3           | 4           | 5           | Avg. time  |
|------------|-------------|-------------|-------------|-------------|-------------|------------|
| 1          | 0.000025105 | 0.000024495 | 0.00002109  | 0.000025388 | 0.000024308 | 0.00002407 |
| 2          | 0.000025332 | 0.000024613 | 0.000023867 | 0.000025222 | 0.000024833 | 0.00002477 |
| 4          | 0.000024973 | 0.000025595 | 0.00002615  | 0.000024303 | 0.00006708  | 0.00003362 |
| 8          | 0.000025912 | 0.000025058 | 0.000025105 | 0.000024748 | 0.000020465 | 0.00002425 |
| 16         | 0.000017596 | 0.00002771  | 0.00006431  | 0.000024572 | 0.000024815 | 0.0000318  |
| 32         | 0.00002552  | 0.000015277 | 0.000026707 | 0.000026348 | 0.000026237 | 0.00002401 |
| 64         | 0.000029943 | 0.000029483 | 0.0000289   | 0.00002419  | 0.000028712 | 0.00002824 |
| 128        | 0.000035895 | 0.000020935 | 0.000036592 | 0.000036005 | 0.00003748  | 0.00003338 |
| 256        | 0.00005041  | 0.00005283  | 0.00005318  | 0.000041813 | 0.000051743 | 0.00004999 |
| 512        | 0.00009209  | 0.000089252 | 0.000094515 | 0.00009622  | 0.000085825 | 0.00009158 |
| 1024       | 0.000155058 | 0.00014358  | 0.000147815 | 0.000148903 | 0.000149233 | 0.00014891 |

![graph](https://github.com/Matas28731449/hash-generator/assets/116190079/0e0beea9-edb6-40fe-a2d2-39c99a263e50)

**Determinism analysis**

*The two files consist of the same, but different, character :*

| Filename    | Hash                                                             |
|-------------|------------------------------------------------------------------|
| symbol1.txt | 0000004100000082000000c3000001040000014500000186000001c700000208 |
| symbol2.txt | 00000061000000c20000012300000184000001e500000246000002a700000308 |

*The two files consist of 1001 randomly generated characters :*

| Filename         | Hash                                                             |
|------------------|------------------------------------------------------------------|
| 1001symbols1.txt | 000155300002aa600003ff90000554c00006a9f00007ff2000095450000aa980 |
| 1001symbols2.txt | 000157470002ae8e000405d500055d1c0006b46300080baa000962f1000aba38 |

*The two files consist of 1001 characters, but differ from each other by only one character :*

| Filename         | Hash                                                             |
|------------------|------------------------------------------------------------------|
| 1001symbolsM.txt | 00014fd300029fa60003ef7900053f4c00068f1f0007def200092ec5000a7e98 |
| 1001symbolsX.txt | 00014fde00029fbc0003ef9a00053f7800068f560007df3400092f12000a7ef0 |

*Empty file:*

| Filename  | Hash                                                             |
|-----------|------------------------------------------------------------------|
| empty.txt | 0000000000000000000000000000000000000000000000000000000000000000 |

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
