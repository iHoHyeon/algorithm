// https://school.programmers.co.kr/learn/courses/30/lessons/77885

const solve = (number) => {
  const bits = number.toString(2);
  const reversed = [...bits].reverse();

  let idx = 0;

  for (const bit of reversed) {
    if (bit === '0') {
      if (idx === 0) {
        return number + 1;
      } else {
        return number + 2 ** (idx - 1);
      }
    }
    idx++;
  }

  return number + 2 ** (bits.length - 1);
};

const solution = (numbers) => numbers.map(solve);

console.log(solution([5, 7]));

/*
    경우의 수는 총 3가지

    1. 비트의 1번째 자리가 0인 경우
        -> 0을 1로 교체하면 원래 수에서 +1만 해주면 OK
            ex. 6 (110) -> 7 (111)

    2. 비트가 전부 1로 이루어진 경우
        -> 비트의 맨 앞에 1이 추가되어야하고 가장 작아지기 위해서 기존 자리에서
           가장 큰 자리의 1을 0으로 교체한다.
            ex. 7 (111) -> 11 (1011) 
    
    3. 비트의 중간에 0이 존재하는 경우
        -> 가장 작은 자리(오른쪽)에 존재하는 0을 1로 교체하고 
           바로 이전 자리의 0을 1로 교체해준다.
*/
