import { StyleSheet, Text, View } from 'react-native';
import React, { useState } from 'react';

const LoginScreen = (props) => {
  const [email, setEmail] = React.useState('');
  const [password, setpassword] = React.useState('');

  const { navigation } = props;

  const styles = StyleSheet.create({
    contenedor_login: {
      display: 'flex',
      justifyContent: 'center',
      alignItems: 'center',
      flexDirection: 'column',
    },
    login_Title: {
      color: 'white',
    },
    h6_login :{
      color: 'white',
    },
    email: {
      borderRadius: '50%',
      border: 'none',
    },
    botonLogin: {
      borderRadius: '50%',
      color: 'white',
      backgroundColor: 'rgb(86, 165, 86)',
    },
  });

  return (
    <View sytle={contenedor_login}>
      <Text style={login_Title}>Login</Text>
      <Image></Image>
      <Text style={h6_login}>Ingresa tus credenciales:</Text>
      <TextInput style={TextInput}/>
      <Button style={botonLogin}/>
    </View>
      /* <div className='contenedor-login'>
        <h1 className='login-Title'>Login</h1>
        <img className="img-informatica"></img>
        <h6 className='h6-Login'>Ingresa tus credenciales:</h6>
        <input type="text" placeholder="Correo Electrónico" className="email"/>
        <input type="text" placeholder="Contraseña" className="password"/>
        <input type="button" value="Ingresar" className="boton-login"/>
      </div> */ 
  );
}

export default LoginScreen;