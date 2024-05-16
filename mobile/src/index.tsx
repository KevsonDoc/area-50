import {View, StyleSheet} from 'react-native';
import {Route} from './route';

export function Main() {
  return (
    <View style={styles.container}>
      <Route />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    backgroundColor: '#FFF',
    flex: 1,
    padding: 10,
  },
});
