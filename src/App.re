open ReactNative;

let fetchFonts = () => {
  Expo.Font.loadAsync([
    ("open-sans", Packager.require("../assets/fonts/OpenSans-Regular.ttf")),
    (
      "open-sans-bold",
      Packager.require("../assets/fonts/OpenSans-Bold.ttf"),
    ),
  ]);
};

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "instructions": style(~textAlign=`center, ~color="#ffffff", ()),
    })
  );

[@react.component]
let app = () => {
  let now = Js.Date.now();
  let initialItems: Model.Items.t = [|
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
  |];

  let (items: Model.Items.t, setItems) = React.useState(() => initialItems);

  let selectedIndex = 1;
  let itemToDecide = items[selectedIndex];

  let acceptHandler = _ =>
    setItems(items =>
      Array.mapi(
        (index, item: Model.Item.t) =>
          index === selectedIndex ? {...item, status: Buyed} : item,
        items,
      )
    );

  let rejectHandler = _ =>
    setItems(items =>
      Array.mapi(
        (index, item: Model.Item.t) =>
          index === selectedIndex ? {...item, status: Discarted} : item,
        items,
      )
    );

  let root =
    switch ("list") {
    | "new" =>
      <New
        onSave=(
          (item: Model.Item.t) =>
            setItems(items => Array.append(items, [|item|]))
        )
      />
    | "buy" =>
      <BuyItem
        item=itemToDecide
        onAccept=acceptHandler
        onReject=rejectHandler
      />
    | "list" => <View> <List items /> </View>
    | _ => <NotFound />
    };

  let (isLoading, setIsLoading) = React.useState(() => true);

  isLoading ?
    <Expo.AppLoading
      startAsync=fetchFonts
      onFinish={_ => setAppLoading(_ => false)}
      onError={e => Js.log(e)}>
      <Text> "Hi"->React.string </Text>
    </Expo.AppLoading> :
    <>
      <StatusBar barStyle=`darkContent />
      <View style=styles##container> root </View>
    </>;
};
