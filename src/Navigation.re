open ReactNative;

[@react.component]
let make = (~route) => {
  let clickHandler = _ => ReasonReactRouter.push("#" ++ route);

  <View> <Button onPress=clickHandler title=route /> </View>;
};
