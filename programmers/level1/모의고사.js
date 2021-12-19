// https://programmers.co.kr/learn/courses/30/lessons/42840

const solution = (answers) => {
  const submit = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ];
  let a = 0,
    b = 0,
    c = 0;
  answers.forEach((v, i) => {
    v === submit[0][i % 5] && a++;
    v === submit[1][i % 8] && b++;
    v === submit[2][i % 10] && c++;
  });

  const m = Math.max(a, b, c);
  const res = [];
  a === m && res.push(1);
  b === m && res.push(2);
  c === m && res.push(3);
  return res;
};
