import {TouchableOpacity, StyleSheet, Text} from 'react-native';

interface ButtonProps {
  type?: 'outline' | 'normal';
  title: string;
  onPress: () => void;
}

export function Button(props: ButtonProps) {
  return (
    <>
      <TouchableOpacity
        onPress={props.onPress}
        style={(() => {
          if (!props.type) {
            return styles.button;
          }

          if (props.type === 'outline') {
            return styles.buttonOutline;
          }

          return styles.button;
        })()}
        activeOpacity={0.9}>
        <Text
          style={(() => {
            if (!props.type) {
              return styles.text;
            }

            if (props.type === 'outline') {
              return styles.textOutline;
            }

            return styles.text;
          })()}>
          {props.title}
        </Text>
      </TouchableOpacity>
    </>
  );
}

const styles = StyleSheet.create({
  button: {
    backgroundColor: '#49aac5',
    height: 50,
    width: '100%',
    borderRadius: 10,
    justifyContent: 'center',
    alignItems: 'center',
  },
  buttonOutline: {
    borderWidth: 1,
    borderStyle: 'solid',
    borderColor: '#49aac5',
    backgroundColor: '#FFF',
    height: 50,
    width: '100%',
    borderRadius: 10,
    justifyContent: 'center',
    alignItems: 'center',
  },

  text: {
    color: '#FFF',
    fontWeight: '700',
  },
  textOutline: {
    color: '#49aac5',
    fontWeight: '700',
  },
});
