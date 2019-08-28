open ReactNative;
open ReactNavigation;
open State;

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
      switch ((status: Item.status)) {
      | Pending => "#eee"
      | Buyed => "#3D9970"
      | Discarted => "#FF4136"
      };

    <TouchableOpacity>
      <View style={styles(color)}>
        <Text>
          {ReasonReact.string(name)}
          {ReasonReact.string(" ")}
          {ReasonReact.string(price)}
          {ReasonReact.string(" ")}
          {ReasonReact.string("Remind in ")}
          <Text> {ReasonReact.string(remindIn)} </Text>
          {ReasonReact.string(" days")}
        </Text>
      </View>
    </TouchableOpacity>;
  };
};

module Empty = {
  [@react.component]
  let make = () =>
    <View>
      <Text> {ReasonReact.string("Here would appear all the whims!")} </Text>
    </View>;
};

let diffInDays = (d1, d2) => {
  let dayInSeconds = float_of_int(1000 * 60 * 60 * 24);
  let diffTime = Js.Date.valueOf(d2) -. Js.Date.valueOf(d1);

  Js.log(diffTime);

  let diffDays = Js.Math.ceil(diffTime /. dayInSeconds);

  diffDays;
};

[@react.component]
let make = (~navigation) => {
  let (state, dispatch) = store.useStore();

  <SafeAreaView>
    <ScrollView>
      <FlatList
        data={state.items}
        keyExtractor={({id}, _) => id}
        renderItem={
          props => {
            let item = props##item;

            /*
               We loop to all the items and trigger them to be selected
                - If the user didn't respond to the notification.
                - If the user have more than one selected.

               let daysPassed = diffInDays(Js.Date.make(), item.createdAt);

               if (daysPassed === item.remindIn) {
                 dispath(SelectItem(item.id))
               }
             */

            <Item
              name={item.name}
              price={item.price}
              createdAt={item.createdAt}
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
      />
      <Button
        title="New +"
        onPress={_ => navigation->Navigation.navigate("New")}
      />
    </ScrollView>
  </SafeAreaView>;
};
