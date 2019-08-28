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

type t = {
  items: Items.t,
  selectedIndex: int,
};

type action =
  | SaveItem(Item.t)
  | BuyItem(int)
  | DiscartItem(int);

let now = Js.Date.now();

let initialState = {
  items: [|
    {
      id: "1337",
      name: "Potenciometro",
      link: "https://www.mammothbikes.com/es/p/electronica/potenciometros/pedales/favero-assioma-duo-24723/41011",
      price: "800",
      remindIn: 15,
      createdAt: now,
      status: Pending,
    },
    {
      id: "9008",
      name: "Rodillo",
      link: "https://es-eu.wahoofitness.com/devices/bike-trainers/wahoo-kickr-powertrainer",
      price: "1200",
      remindIn: 10,
      createdAt: now,
      status: Pending,
    },
    {
      id: "1000",
      name: "Nike Zoom Fly",
      link: "http://masses.com.my/sneakers/nike-updates-zoom-fly-react-foam/",
      price: "160",
      remindIn: 0,
      createdAt: now,
      status: Pending,
    },
    {
      id: "1001",
      name: "Origen by Dan Brown",
      link: "",
      price: "19",
      remindIn: 15,
      createdAt: now,
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
  | BuyItem(selectedIndex) => {
      ...state,
      items:
        Array.mapi(
          (index, item: Item.t) =>
            index === selectedIndex ? {...item, status: Buyed} : item,
          state.items,
        ),
    }
  | DiscartItem(selectedIndex) => {
      ...state,
      items:
        Array.mapi(
          (index, item: Item.t) =>
            index === selectedIndex ? {...item, status: Discarted} : item,
          state.items,
        ),
    }
  };

let store = Restorative.createStore(initialState, reducer);
