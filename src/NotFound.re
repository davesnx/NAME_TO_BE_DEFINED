open ReactNative;

[@react.component]
let make = () =>
  <View>
    <Text> {ReasonReact.string("We are sorry...")} </Text>
    <Text>
      {
        ReasonReact.string(
          "Unfortunately we could not find the page you were looking for.",
        )
      }
    </Text>
    <Text>
      {ReasonReact.string("Use the above menu to navigate to other pages :)")}
    </Text>
  </View>;
