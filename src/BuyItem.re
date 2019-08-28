open ReactNative;

[@react.component]
let make = (~item: State.Item.t, ~onAccept, ~onReject) =>
  <View>
    <Text> {ReasonReact.string(item.name)} </Text>
    <View>
      <Button onPress=onAccept title="Accept" />
      <Button onPress=onReject title="Reject" />
    </View>
  </View>;
