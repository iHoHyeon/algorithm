// https://programmers.co.kr/learn/courses/30/lessons/12977

const p = new Array(3000).fill(true);
for (let i = 2; i < 3000; i++) {
  if (p[i]) for (let j = i + i; j < 3000; j += i) p[j] = false;
}
const solution = (nums) => {
  let ans = 0;
  for (let i = 0; i < nums.length - 2; i++) {
    for (let j = i + 1; j < nums.length - 1; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        if (p[nums[i] + nums[j] + nums[k]]) ans++;
      }
    }
  }
  return ans;
};

/*
  에라토스테네스의 체
*/
