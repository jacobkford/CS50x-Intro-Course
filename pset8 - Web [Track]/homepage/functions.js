function submitted()
{
    let name = document.querySelector('#name').value;
    let email = document.querySelector('#email').value;
    let message = document.querySelector('#message').value;

    if (name === '')
    {
        alert('Error! You did not input your name.')
        return;
    }

    if (email === '')
    {
        alert('Error! You did not input your email.') 
        return;
    }

    if (message === '')
    {
        alert('Error! You did not input a message.')
        return;
    }

    alert('Thank you ' + name + ', your message has been sent!');
}