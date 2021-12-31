// https://programmers.co.kr/learn/courses/30/lessons/68935

const solution = (n) => {
  let st = '';
  while (n) {
    st = (n % 3) + st;
    n = parseInt(n / 3);
  }
  return [...st].reduce(($, _, i) => $ + Math.pow(3, i) * _, 0);
};

const solution = (n) => parseInt([...n.toString(3)].reverse().join(''), 3);

/*
  toString(n) 메서드를 사용하면 10진법을 n진법 string으로 return 받을 수 있다
  parseInt 또한 n진법을 10진법으로 변환 가능하다.
*/
