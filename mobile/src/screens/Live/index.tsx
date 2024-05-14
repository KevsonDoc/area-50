import {StyleSheet, View} from 'react-native';
import {Button} from '../../components/Buttton';
import {NavigationType} from '../../types/route';

interface LiveScreenProps {
  navigation: NavigationType;
}

export function LiveScreen({navigation}: LiveScreenProps) {
  return (
    <View style={styles.container}>
      <View style={styles.chartContainer} />
      <Button
        type="outline"
        onPress={() => {
          navigation.goBack();
        }}
        title="Voltar"
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    gap: 10,
    justifyContent: 'center',
    backgroundColor: '#FFF',
  },
  chartContainer: {
    flex: 1,
    width: 'auto',
    backgroundColor: '#000',
  },
});
