function solution(arr1, arr2) {
  return arr1.reduce((acc2, row) => {
    const calculatedRow = arr2[0].reduce((acc1, _, calIdx) => {
      const calculatedEl = row.reduce((sum, el, rowIdx) => {
        return sum + el * arr2[rowIdx][calIdx];
      }, 0);
      return [...acc1, calculatedEl];
    }, []);
    return [...acc2, calculatedRow];
  }, []);
}

/*
    명령형 구현
*/
