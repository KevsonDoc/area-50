import {JSX} from 'react';
import Theme from './assets/theme';
import HomeScreen from './screens/Home';

export default function App(): JSX.Element {
  return (
    <Theme>
      <HomeScreen />
    </Theme>
  );
}
