module Item = {
  type status =
    | Pending
    | Buyed
    | Discarted;

  type t = {
    id: string,
    name: string,
    link: string,
    price: string,
    remindIn: int,
    createdAt: float,
    status,
  };
};

module Items = {
  type t = array(Item.t);
};
