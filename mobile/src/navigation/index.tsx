import {NavigationContainer} from '@react-navigation/native';
import {JSX} from 'react';
import Theme from '../assets/theme';
import {StackNavigation} from './StackNavigation';

export function Navigation(): JSX.Element {
  return (
    <NavigationContainer>
      <Theme>
        <StackNavigation />
      </Theme>
    </NavigationContainer>
  );
}
