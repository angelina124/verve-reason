open Constants;

let gte = (>=);
let validUsername = (~username) =>
  String.length(username)->gte(_, minUsernameLength);
let validPassword = (~password) =>
  String.length(password)->gte(_, minPasswordLength);