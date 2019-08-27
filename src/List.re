open ReactNative;

let styles = color =>
  Style.style(
    ~flex=1.,
    ~justifyContent=`center,
    ~alignItems=`center,
    ~backgroundColor=color,
    (),
  );

module Item = {
  [@react.component]
  let make = (~name, ~status, ~price, ~createdAt, ~remindIn) => {
    let color =
      switch ((status: Model.Item.status)) {
      | Pending => "#eee"
      | Buyed => "#3D9970"
      | Discarted => "#FF4136"
      };

    <View style={styles(color)}>
      <Text>
        {ReasonReact.string(". ")}
        {ReasonReact.string(name)}
        {ReasonReact.string(price)}
        {ReasonReact.string("Created at ")}
        <Text> {ReasonReact.string(createdAt)} </Text>
        {ReasonReact.string("Remind in ")}
        <Text> {ReasonReact.string(remindIn)} </Text>
        {ReasonReact.string(" days")}
      </Text>
    </View>;
  };
};

module Empty = {
  [@react.component]
  let make = () =>
    <View>
      <Text> {ReasonReact.string("Here would appear all the whims!")} </Text>
    </View>;
};

[@react.component]
let make = (~items: Model.Items.t) =>
  <FlatList
    /* <View> <Navigation route="new" /> childrens </View>; */
    data=items
    keyExtractor={({id}, _) => id}
    renderItem={
      props => {
        let item = props##item;
        /* let now = Js.Date.now();
           let remindInMs = float_of_int(item.remindIn * 24 * 60 * 60 * 1000); */
        /* let remindDate = Js.Date.fromFloat(remindInMs +. now); */

        /*
           TODO: When we have a timer to decrease, we would need that:
            let daysLeftInMs = remindInMs +. item.createdAt;
            let daysLeft = Js.Date.fromFloat(daysLeftInMs);
         */

        let createdAtDate = Js.Date.fromFloat(item.createdAt);

        <Item
          name={item.name}
          price={item.price}
          createdAt={Js.Date.toLocaleDateString(createdAtDate)}
          /* remindDate={Js.Date.toLocaleDateString(remindDate)} */
          remindIn={string_of_int(item.remindIn)}
          status={item.status}
          /* onPress={
               /* _ =>
                  navigation
                  ->Navigation.navigateWithParams("Item", {"item": props##item}) */
             } */
        />;
      }
    }
  />;
