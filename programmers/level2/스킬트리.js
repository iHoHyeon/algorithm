// https://school.programmers.co.kr/learn/courses/30/lessons/49993

function solution(skill, skill_trees) {
  const answer = skill_trees.reduce((acc, tree) => {
    let currentSkillIdx = 0;
    let isPossible = true;

    for (const s of tree) {
      const skillIdx = skill.indexOf(s);

      if (skillIdx === -1) {
        continue;
      }

      if (skillIdx === currentSkillIdx) {
        currentSkillIdx++;
      } else {
        isPossible = false;
        break;
      }
    }

    return isPossible ? acc + 1 : acc;
  }, 0);

  return answer;
}
