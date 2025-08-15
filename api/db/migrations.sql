drop table if exists roles; 
create table roles (
  id integer primary key autoincrement,
  role varchar(255) unique
);

drop table if exists users; 
create table users (
  id integer primary key autoincrement,
  username varchar(255) unique,
  password varchar(255),
  first_name varchar(155),
  last_name varchar(155),

  role_id integer,

  foreign key (role_id) references roles(id)
);

drop table if exists tokens; 
create table tokens (
  id integer primary key autoincrement,
  token varchar(255),

  user_id integer,

  foreign key (user_id) references users(id)
);
