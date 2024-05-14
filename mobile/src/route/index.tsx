import {createNativeStackNavigator} from '@react-navigation/native-stack';
import {LiveScreen} from '../screens/Live';
import {HomeScreen} from '../screens/Home';
import {HistoryScreen} from '../screens/History';
import {NavigationContainer} from '@react-navigation/native';
const {Navigator, Screen} = createNativeStackNavigator();

export function Route() {
  return (
    <NavigationContainer>
      <Navigator
        screenOptions={{
          headerShown: false,
          animation: 'fade',
        }}
        initialRouteName="Home">
        <Screen name="Home" component={HomeScreen} />
        <Screen name="Live" component={LiveScreen} />
        <Screen name="History" component={HistoryScreen} />
      </Navigator>
    </NavigationContainer>
  );
}
