let path = "http://localhost:3000/api/";

type todo_route = string;
type user_route = string;
type reward_route = string;

type routes = {
  todos: todo_route,
  completeTodo: todo_route,
  addTodo: todo_route,
  addReward: reward_route,
  rewards: reward_route,
  user: user_route,
  login: user_route,
};

let routes = {
  todos: path ++ "todos/",
  completeTodo: path ++ "todos/complete/",
  addTodo: path ++ "todos/",
  rewards: path ++ "rewards/",
  addReward: path ++ "rewards/",
  user: path ++ "users/",
  login: path ++ "users/login",
};