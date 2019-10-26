open ReactNative;
open ReactNavigation;
open State;

let s = React.string;

let styles =
  Style.(
    StyleSheet.create({
      "screen":
        viewStyle(
          ~height=100.->pct,
          ~width=100.->pct,
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          (),
        ),
      "list": style(~padding=20.->dp, ~width=100.->pct, ()),
    })
  );

module Empty = {
  [@react.component]
  let make = () =>
    <View> <Text> {s("Here would appear all the whims!")} </Text> </View>;
};

module Header = {
  [@react.component]
  let make = (~numberOfItems) =>
    <View>
      <Text> {s("Good morning!")} </Text>
      <Text>
        {
          switch (numberOfItems) {
          | 0 => s("There are not whims created, yet!")
          | _ =>
            s("You have " ++ string_of_int(numberOfItems) ++ " whims added")
          }
        }
      </Text>
    </View>;
};

let diffInDays = (d1, d2) => {
  let dayInSeconds = float_of_int(1000 * 60 * 60 * 24);
  let diffTime = Js.Date.valueOf(d2) -. Js.Date.valueOf(d1);

  let diffDays = Js.Math.ceil(diffTime /. dayInSeconds);

  diffDays;
};

module Item = {
  let styles =
    Style.(
      StyleSheet.create({
        "image":
          style(
            ~width=100.->pct,
            ~height=200.->dp,
            ~backgroundColor=Theme.Color.darkblue,
            ~borderRadius=10.,
            (),
          ),
        "title":
          viewStyle(
            ~marginTop=20.->dp,
            ~marginBottom=10.->dp,
            ~width=100.->pct,
            ~flex=1.,
            ~justifyContent=`center,
            ~alignItems=`flexStart,
            (),
          ),
        "subtitle":
          viewStyle(
            ~marginTop=10.->dp,
            ~flex=1.,
            ~flexDirection=`row,
            ~justifyContent=`center,
            ~alignItems=`center,
            (),
          ),
        "separator":
          viewStyle(
            ~marginHorizontal=10.->dp,
            ~width=1.->dp,
            ~height=20.->dp,
            ~backgroundColor=Theme.Color.grey,
            (),
          ),
        "itemName": Theme.Typo.bo,
        "item":
          viewStyle(
            ~width=100.->pct,
            ~flex=1.,
            ~justifyContent=`center,
            ~alignItems=`center,
            ~paddingVertical=24.->dp,
            (),
          ),
        "name": style(~textAlign=`left, ()),
      })
    );

  [@react.component]
  let make = (~name, ~status: Item.status, ~price, ~currency, ~remindIn) =>
    <TouchableOpacity style=styles##item>
      <View style=styles##image />
      <View style=styles##title>
        <Text style=styles##itemName> {s(name)} </Text>
        <View style=styles##subtitle>
          <Text style=Theme.Typo.h2>
            {
              switch (currency) {
              | `D => s("$" ++ price)
              | `E => s(price ++ "€")
              }
            }
          </Text>
          <View style=styles##separator />
          <Text style=Theme.Typo.di> {s(remindIn ++ " days left")} </Text>
        </View>
      </View>
    </TouchableOpacity>;
};

[@react.component]
let make = (~navigation) => {
  let (state, _dispatch) = store.useStore();
  let itemCount = Belt.Array.length(state.items);

  <SafeAreaView style=styles##screen>
    <Header numberOfItems=itemCount />
    {
      switch (Belt.Array.length(state.items)) {
      | 0 => <Empty />
      | _ =>
        <FlatList
          style=styles##list
          data={state.items}
          keyExtractor=(({id}, _) => id)
          renderItem=(
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
                /* remindDate={Js.Date.toLocaleDateString(remindDate)} */
                remindIn={string_of_int(item.remindIn)}
                status={item.status}
                currency={state.settings.currency}
                /* onPress={
                     /* _ =>
                        navigation
                        ->Navigation.navigateWithParams("Item", {"item": props##item}) */
                   } */
              />;
            }
          )
        />
      }
    }
    <Button
      title="New +"
      onPress={_ => navigation->Navigation.navigate("New")}
    />
  </SafeAreaView>;
};
