// https://programmers.co.kr/learn/courses/30/lessons/72411

const checkCorrect = (s) => {
  const stack = [];
  [...s].forEach((c) => {
    if (stack.length === 0 && c === ')') return false;
    c === '(' ? stack.push(c) : stack.pop();
  });
  return !stack.length;
};

const solution = (p) => {
  if (!p) return p;

  p = [...p];
  let u = [];
  let v;
  let left = 0;
  let right = 0;

  while (true) {
    const temp = p.shift();
    temp === '(' ? left++ : right++;
    u.push(temp);
    if (left === right) {
      v = p.join('');
      break;
    }
  }

  if (checkCorrect(u.join(''))) return u.join('') + solution(v);
  else
    return (
      '(' +
      solution(v) +
      ')' +
      u
        .slice(1, -1)
        .map((c) => (c === '(' ? ')' : '('))
        .join('')
    );
};

/*
  String을 Array로 변환해서 풀었지만 변환하지 않고도 풀이가 가능하다.
  또한 while 무한루프와 break 대신 do - while 문을 이용할 수 있다.
*/
