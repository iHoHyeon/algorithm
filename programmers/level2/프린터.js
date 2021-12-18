// https://programmers.co.kr/learn/courses/30/lessons/86052

const solution = (priorities, location) => {
  let res = 1;

  while (priorities.length) {
    if (priorities[0] < Math.max(...priorities)) {
      if (--location === -1) location = priorities.length - 1;
      priorities.push(priorities.shift());
    } else {
      if (location === 0) return res;

      priorities.shift();
      location--;
      res++;
    }
  }
};

/*
  `priorities[0] < Math.max(...priorities)` 이 부분에서 `some`을 사용할 수도 있었다
  중요한 건 아니지만 `if (--location === -1) return res;` 으로 썼다면 코드 한 줄을 줄일수도..

*/
