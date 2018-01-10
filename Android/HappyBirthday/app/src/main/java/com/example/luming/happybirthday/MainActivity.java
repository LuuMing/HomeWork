package com.example.luming.happybirthday;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.AlteredCharSequence;
import android.util.Log;
import android.view.View;
import android.widget.CheckBox;
import android.widget.TextView;

import java.text.NumberFormat;

public class MainActivity extends AppCompatActivity {
    int quantity = 2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        display(quantity);
        display_price(quantity);
    }
    /*
    * this method is called when the plus button is clicked
    */
    public void increase(View view)
    {
        quantity++;
        display(quantity);
    }
    public void submitOrder(View view)
    {
        display(quantity);
        display_price(quantity);
        String information = getInformation();
        TextView text = findViewById(R.id.information);
        text.setText(information);
        Intent intend = new Intent(Intent.ACTION_CALL).setData(Uri.parse("tel:13201709703"));
        if(intend.resolveActivity(getPackageManager())!=null)
        {
            startActivity(intend);
        }

    }
    private String getInformation()
    {
        String name = "LuMing";
        String sex = "male";
        String address = "西安建筑科技大学草堂校区";
        return name+"\n"+sex+"\n"+address;

    }
    public void decrease(View view){
        if(quantity==0)
        {
            AlertDialog dialog = new AlertDialog.Builder(this).setTitle("错误").setMessage("数量不能少于0").setCancelable(true).create();
            dialog.show();
        }
        else
        {
            quantity--;
            display(quantity);
        }
    }
    private int calculate_price()
    {
        CheckBox checkbox = findViewById(R.id.isCoffee);
        return 2*quantity+3* (checkbox.isChecked()==true?1:0);
    }
    private void display(int number)
    {
        TextView quantityTextView = (TextView)findViewById(R.id.quantity);
        quantityTextView.setText(""+number);
    }
    private void display_price(int number)
    {
        TextView priceView = (TextView)findViewById(R.id.price);
        priceView.setText(NumberFormat.getCurrencyInstance().format(calculate_price()));
    }
}
