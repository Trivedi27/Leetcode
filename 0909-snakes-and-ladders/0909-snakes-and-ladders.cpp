int n = b.size();
vector<int> min_rolls(n * n + 1, -1);
queue<int> q;
min_rolls[1] = 0;
q.push(1);