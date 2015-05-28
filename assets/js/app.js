var main = function(){
    $('.add-btn').click( function(){
        $('#myCheckBox').attr('checked', false); // Unchecks it
        var post1 = $('#class-code').val();
        var post2 = $('#class-number').val();
        var post = post1 +" " + post2;
        var icon = $('<span class="remove-btn glyphicon glyphicon-remove pull-right"></span>');
        $(icon).appendTo($('<li>').text(post).appendTo('.classes'));
        $('.text-box').val('');
        $('.add-btn').addClass('disabled');
    });
 //   var availableTags = ["MATH", "CS", "CI", "ENGL", "CHEM", "PHYS", "ECON"];
 //   $('#class-code').autocomplete({
 //     source: availableTags
 //   });
     $('.add-btn').addClass('disabled');
    $('.text-box').keyup( function(){
    $('.add-btn').removeClass('disabled');
    });
   $(document).on('click','.remove-btn', function(){
            $(this).parent().remove();
   });
   $('.sched-btn').click( function(){
        $.ajax({
                url:'sched.php',
                success: function()
                {
                    alert('Chạy rồi. Thật không thể tin được.');
                }
        });
        return false;
   });
};

$(document).ready(main);
