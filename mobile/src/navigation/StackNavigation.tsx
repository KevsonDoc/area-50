import {createStackNavigator} from '@react-navigation/stack';
import HomeScreen from '../screens/Home';
import {HumidityScreen} from '../screens/Humidity';
import {TemperatureScreen} from '../screens/Temperature';

const Stack = createStackNavigator();

export function StackNavigation() {
  return (
    <Stack.Navigator
      screenOptions={{
        headerShown: false,
        cardStyle: {
          backgroundColor: 'transparent',
        },
      }}>
      <Stack.Screen name="Home" component={HomeScreen} />
      <Stack.Screen name="Temperature" component={TemperatureScreen} />
      <Stack.Screen name="Humidity" component={HumidityScreen} />
    </Stack.Navigator>
  );
}
