// https://programmers.co.kr/learn/courses/30/lessons/67257

const ranks = [
  ['*', '+', '-'],
  ['*', '-', '+'],
  ['+', '*', '-'],
  ['+', '-', '*'],
  ['-', '*', '+'],
  ['-', '+', '*'],
];

const solution = (e) => {
  let res = 0;
  ranks.forEach((p) => {
    let exps = e.split(/(\+|\-|\*)+/);
    p.forEach((c) => {
      const temp = [];
      for (let i = 0; i < exps.length; i++) {
        if (exps[i] === c) {
          temp.push(eval(temp.pop() + c + exps[++i]));
        } else {
          temp.push(exps[i]);
        }
      }
      exps = [...temp];
    });
    res = Math.max(Math.abs(exps[0]), res);
  });
  return res;
};
