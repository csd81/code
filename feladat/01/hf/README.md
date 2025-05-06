# Assignment Specification

- Use references and constants where possible.
- Define a `struct subject` that stores a course’s results, with members:
  - `code`: a string (no spaces)
  - `gradeCount`: an unsigned integer
  - `grades`: a dynamic array of unsigned integers
- Place `subject` and the following functions inside the `university` namespace, and add the necessary `using` declarations so that `main` can call them unqualified.
- Fixed storage for exactly three subjects—your program must manage results for 3 courses.
- Read in each subject’s data:
  1. Prompt for the number of grades.
  2. Allocate a dynamic array of that size.
  3. Read the individual grades into that array.
- Implement `void printSubject(const subject&)` to display a subject’s code, grade count, and all its grades. Use this function to print all three subjects.
- Implement `double average(const subject&)` to compute and return the average of a subject’s grades.
- Using `average`, find the subject with the highest average and display its full data.
- Implement `void resize(subject&, unsigned newSize)` to reallocate a subject’s grade array to `newSize`:
  - If `newSize` is smaller, discard any trailing grades.
  - If `newSize` is larger, initialize all new entries to `5`.
- Overload `void resize(subject&, unsigned newSize, unsigned a, unsigned b)`:
  - When growing, fill new slots alternately with `a` and `b` (e.g. for parameters `2` and `4` and 5 new slots, the values should be `2, 4, 2, 4, 2`).
- Prompt for a new size for each subject in `main` and call the appropriate `resize` overload accordingly.
- Implement `void freeMemory(subject&)` to delete a subject’s dynamic array and reset its pointer. Call it for each subject at the very end to release all allocated memory.
