#include <stdlib.h>

#include <stdio.h>

#include <math.h>


int n = 6;

void print(int v[]) {

  for (int i = 0; i < n; i++) {

    printf("%d ", v[i]);
  }

  return;

}

int count_choices(int choices[]) {

  int count = 0;

  for (int i = 0; i < n; i++) {

    if (choices[i] != -1) count++;

  }

  return count;

}

int insert_next(int v[], int choices[], int index, int reps_at_index) {

  int backup;

  int flag = reps_at_index+1;

  for (int i = 0; i < n; i++) {

    if (choices[i] != -1) {

      flag--;

      if (flag == -1) {

        backup = choices[i];

        v[index] = choices[i];

        

        choices[i] = -1;

        return backup;


      }
    }

  }

}

void copy_arr(int v1[], int v2[]) {

  for (int i = 0; i < n; i++) {

    v2[i] = v1[i];

  }
}

int control(int v[], int guard[3][6]) {

  for (int j = 0; j < 2 ; j++) {

    for (int i = 0; i < n; i++) {

      if (v[i] == guard[j][i] || v[i] == i) return 0;

    }

  }

  return 1;

}

void complete(int v[], int index, int reps[], int choices[], int guard[3][6], int choices_backups[]) {

  printf("\n--CURRENT INDEX: %d-------", index);

  printf("\nARRAY:[");
        print(v);
        printf("]");

  printf("\nREPS:[");
        print(reps);
        printf("]");

        

        printf("\nCHOICES:[");
        print(choices);
        printf("]");

        //printf("\nCHOICES BACKUPS:[");
        //print(choices_backups);
        //printf("]");

        

  if (index == n) {
    printf("\n--FINISH---");
    print(v);
  } else {
    int aux_arr[] = {
      -3,
      -3,
      -3,
      -3,
      -3,
      -3
    };
    copy_arr(v, aux_arr);
    int backup = -4;
    backup = insert_next(aux_arr, choices, index, reps[index]);
    if (control(aux_arr, guard)) {
      printf("\n---PASS---/n");
      copy_arr(aux_arr, v);
      complete(v, index + 1, reps, choices, guard, choices_backups);
    } else {
      reps[index]++;
      choices[backup] = backup;
      if (reps[index] > count_choices(choices)) {
        printf("\n--PROBLEM, COUNTCHOICES: %d---", index, count_choices(choices));
        choices[v[index - 1]] = v[index - 1];
        v[index] = -2;
        v[index - 1] = -2;
        reps[index] = 1;
        reps[index - 1]++;
        complete(v, index - 1, reps, choices, guard, choices_backups);
      } else {
        printf("\n---FAIL---", index);
        complete(v, index, reps, choices, guard, choices_backups);
      }
    }
  }
}

int main() {

  int base[3][6] = {
    {
      5,
      4,
      3,
      1,
      0,
      2
    }
  };

  int next[] = {
    -2,
    -2,
    -2,
    -2,
    -2,
    -2
  };

  int reps[] = {
    1,
    1,
    1,
    1,
    1,
    1
  };

  int choices[] = {
    0,
    1,
    2,
    3,
    4,
    5
  };

  int choices_backups[] = {
    0,
    0,
    0,
    0,
    0,
    0
  };

  complete(next, 0, reps, choices, base, choices_backups);

  return 0;

}