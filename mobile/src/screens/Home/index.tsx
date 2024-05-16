import {StyleSheet, View} from 'react-native';
import {Button} from '../../components/Buttton';
import {NavigationType} from '../../types/route';

interface HomeScreenProps {
  navigation: NavigationType;
}

export function HomeScreen({navigation}: HomeScreenProps) {
  return (
    <View style={styles.container}>
      <Button
        onPress={() => {
          navigation.navigate('Live');
        }}
        title="Tempo real"
      />
      <Button
        onPress={() => {
          navigation.navigate('History');
        }}
        title="Histórico"
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    gap: 10,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#FFF',
  },
});
