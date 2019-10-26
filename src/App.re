open ReactNative;
open ReactNavigation;
open State;

let fetchFonts = () =>
  Expo.Font.loadAsync([
    ("lexend-deca", Packager.require("../assets/fonts/LexendDeca.ttf")),
  ]);

let styles =
  Style.(
    style(
      ~flex=1.,
      ~justifyContent=`center,
      ~alignItems=`center,
      ~backgroundColor="#F5FCFF",
      (),
    )
  );

module Nav =
  AppContainer.Make({
    type screenProps = {.};

    let navigator =
      StackNavigator.make({
        "List": List.make,
        "New": New.make,
        "Settings": NotFound.make,
        "Item": NotFound.make,
        "Buy": BuyItem.make,
      });
  });

[@react.component]
let app = () => {
  let (state, dispatch) = store.useStore();
  let (isLoading, setIsLoading) = React.useState(() => true);

  <Nav />;
};
