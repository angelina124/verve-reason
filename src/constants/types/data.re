type id = string;

type todo = {
  _id: id,
  text: string,
  points: int,
};

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
  todoLists: list(list(todo)),
  rewards: list(reward),
};

type loginFields = {
  username: string,
  password: string,
};