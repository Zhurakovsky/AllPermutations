# AllPermutations

Steps:
1. Convert long number to the vector of digits
2. Find all permutations of the longest sequence
3. Rotate vector step by step
    3.1 Find all permutations of the shortest subvectors
4. Reduce number of overhead calculations by providing of global set of calculated subsequences.
5. Obtained results:
    /*
    Digits  | Number of permutations
      1     |       1
      2     |       4
      3     |       15
      4     |       60
      5     |       285
      6     |       1638
      7     |       11151
      8     |       87624
      9     |       778977
      10    |       6901705
    */
