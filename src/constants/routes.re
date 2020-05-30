let path = "http://localhost:3000/api/";

type todo_route = string;
type user_route = string;

type routes = {
  todos: todo_route,
  completeTodo: todo_route,
  user: user_route,
  login: user_route,
};

let routes = {
  todos: path ++ "todos/",
  completeTodo: path ++ "todos/complete/",
  user: path ++ "users/",
  login: path ++ "users/login",
};