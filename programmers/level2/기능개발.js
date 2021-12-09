// https://programmers.co.kr/learn/courses/30/lessons/42586

const solution = (p, s) => {
  const days = p.map((v1, i) => Math.ceil((100 - v1) / s[i]));
  let nowMax = days[0],
    nowTask = 1;
  const res = [];
  for (let i = 1; i < days.length; i++) {
    if (i === days.length - 1) {
      if (nowMax < days[i]) {
        res.push(nowTask);
        nowTask = 0;
      }
      res.push(++nowTask);
      break;
    }
    if (nowMax < days[i]) {
      res.push(nowTask);
      nowMax = days[i];
      nowTask = 1;
    } else {
      nowTask++;
    }
  }
  return res;
};

/*
  cpp에서 while을 돌면서 스택으로 풀어봤던 문제들과 비슷한 유형이다.

  단순히 조건 나누기로 풀었는데 조건을 더 단순하게 나눌 수 있었다.
  => 내 풀이는 현재 for루프를 돌면서 현재 배포될 개수를 저장하는데, 굳이 따로 저장하지 않고
     res의 인덱스를 지정하여 현재 최댓값보다 작거나 같으면 현재 res 인덱스를 ++, 아니라면 다음 인덱스에 1을 저장한다.

  => JS의 특성을 이용하자
*/
