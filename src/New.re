open ReactNative;
open ReactNavigation;
open State;

module Input = {
  [@react.component]
  let make = (~placeholder, ~value, ~onChangeText) =>
    <View> <TextInput placeholder value onChangeText /> </View>;
};

module SaveButton = {
  [@react.component]
  let make = (~disabled, ~onClick) =>
    <View> <Button disabled onPress=onClick title="Save" /> </View>;
};

[@react.component]
let make = (~navigation) => {
  let (_state, dispatch) = store.useStore();
  let (name, setName) = React.useState(() => "");
  let (link, setLink) = React.useState(() => "");
  let (price, setPrice) = React.useState(() => "");
  let (date, setDate) = React.useState(() => 15);

  let clickHandler = _ => {
    setName(_ => "");
    setLink(_ => "");
    setPrice(_ => "");

    dispatch(
      SaveItem(
        {
          id: string_of_int(Random.int(String.length(name) * 1000)),
          name,
          link,
          price,
          remindIn: date,
          createdAt: Js.Date.make(),
          status: Pending,
        }: Item.t,
      ),
    );

    navigation->Navigation.navigate("List");
  };

  let disabled = name === "";

  <View>
          <Input
            value=name
            placeholder="What you would like to buy"
            onChangeText={value => setName(_ => value)}
          />
        </View> /*
    <Input
      value=price
      label="price"
      placeholder="15 $"
      onChangeText={value => setPrice(_ => value)}
    />
    <TextInput
      keyboardType=`numeric
      value={string_of_int(date)}
      placeholder="15"
      onChangeText={value => setDate(_ => int_of_string(value))}
    />
    <Text> {ReasonReact.string("days")} </Text>
    <SaveButton disabled onClick=clickHandler />
  */;
};
