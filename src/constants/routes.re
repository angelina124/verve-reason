open Settings;

let mode = DEVELOP;

let path =
  switch (mode) {
  | PRODUCTION => "https://verve-api.herokuapp.com/api/"
  | DEVELOP => "http://localhost:3000/api/"
  };

type todo_route = string;
type user_route = string;
type reward_route = string;

type routes = {
  todos: todo_route,
  completeTodo: todo_route,
  rewards: reward_route,
  user: user_route,
  login: user_route,
};

let routes = {
  todos: path ++ "todos/",
  completeTodo: path ++ "todos/complete/",
  rewards: path ++ "rewards/",
  user: path ++ "users/signup",
  login: path ++ "users/login",
};