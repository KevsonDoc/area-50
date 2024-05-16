import {NativeStackNavigationProp} from '@react-navigation/native-stack';

type RootStackParamList = {
  Home: undefined;
  Live: undefined;
  History: undefined;
};

export type NavigationType = NativeStackNavigationProp<
  RootStackParamList,
  'Home' | 'History' | 'Live'
>;
