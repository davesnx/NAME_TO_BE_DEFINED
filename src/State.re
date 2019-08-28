open Restorative;

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
    createdAt: Js.Date.t,
    status,
  };
};

module Items = {
  type t = array(Item.t);
};

type t = {
  items: Items.t,
  selectedIndex: int,
};

type action =
  | SaveItem(Item.t)
  | BuyItem(int)
  | DiscartItem(int);

let ago30 = Js.Date.makeWithYMD(~year=2019., ~month=08., ~date=23., ());
let ago20 = Js.Date.makeWithYMD(~year=2019., ~month=08., ~date=23., ());
let ago10 = Js.Date.makeWithYMD(~year=2019., ~month=08., ~date=23., ());

let initialState = {
  items: [|
    {
      id: "1337",
      name: "Potenciometro",
      link: "https://www.mammothbikes.com/es/p/electronica/potenciometros/pedales/favero-assioma-duo-24723/41011",
      price: "800",
      remindIn: 15,
      createdAt: ago30,
      status: Pending,
    },
    {
      id: "9008",
      name: "Rodillo",
      link: "https://es-eu.wahoofitness.com/devices/bike-trainers/wahoo-kickr-powertrainer",
      price: "1200",
      remindIn: 10,
      createdAt: ago30,
      status: Pending,
    },
    {
      id: "1000",
      name: "Nike Zoom Fly",
      link: "http://masses.com.my/sneakers/nike-updates-zoom-fly-react-foam/",
      price: "160",
      remindIn: 15,
      createdAt: ago20,
      status: Pending,
    },
    {
      id: "1001",
      name: "Origen by Dan Brown",
      link: "",
      price: "19",
      remindIn: 35,
      createdAt: ago10,
      status: Pending,
    },
  |],
  selectedIndex: 1,
};

let reducer = (state, action) =>
  switch (action) {
  | SaveItem(item) => {
      ...state,
      items: Array.append(state.items, [|item|]),
    }
  | BuyItem(itemIndex) => {
      ...state,
      items:
        Array.mapi(
          (index, item: Item.t) =>
            index === itemIndex ? {...item, status: Buyed} : item,
          state.items,
        ),
    }
  | DiscartItem(itemIndex) => {
      ...state,
      items:
        Array.mapi(
          (index, item: Item.t) =>
            index === itemIndex ? {...item, status: Discarted} : item,
          state.items,
        ),
    }
  };

let store = createStore(initialState, reducer);
