type id = string;

type todo = {
  _id: id,
  text: string,
  points: int,
};

type todolist = {
  _id: id,
  completedTodos: list(todo),
  title: string,
  todos: list(todo)
}

type reward = {
  _id: id,
  text: string,
  points: int,
};

type new_todo = {
  text: string,
  points: int,
};

type user = {
  _id: string,
  username: string,
  todolists: array(todolist),
  rewards: list(reward),
};

type loginFields = {
  username: string,
  password: string,
};