import {JSX, useContext, useEffect} from 'react';
import {Text, View} from 'react-native';
import {ThemeContext} from 'styled-components/native';

export default function HomeScreen(): JSX.Element {
  const themeContext = useContext(ThemeContext);

  useEffect(() => {
    console.log(themeContext);
  }, [themeContext]);

  return (
    <View>
      <Text onPress={() => themeContext?.setTheme()}>Hello World</Text>
    </View>
  );
}
